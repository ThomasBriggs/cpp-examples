#include <cstdlib>
#include <cstring>
#include <curl/curl.h>
#include <iostream>

struct memory {
    char* response;
    size_t size;
};

static size_t cb(void* data, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    memory* mem = (memory*)userp;

    char* ptr = (char*)std::realloc(mem->response, mem->size + realsize + 1);
    if (ptr == NULL)
        return 0; /* out of memory! */

    mem->response = ptr;
    std::memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}

int main()
{
    memory chunk = {(char*)std::malloc(0), 0};
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://opentdb.com/api.php?amount=1");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);

        std::cout << chunk.response << '\n';
        return 0;
    }
}
