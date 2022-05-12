FROM cmake

RUN useradd -m dev
COPY script.sh /home/dev/script.sh
RUN chmod +x /home/dev/script.sh
USER dev
WORKDIR /home/dev/src
ENTRYPOINT ["/home/dev/script.sh"]
CMD ["main"]