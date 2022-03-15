// Written by Ch. Tronche (http://tronche.lri.fr:8000/)
// Copyright by the author. This is unmaintained, no-warranty free software. 
// Please use freely. It is appreciated (but by no means mandatory) to
// acknowledge the author's contribution. Thank you.
// Started on Thu Jun 26 23:29:03 1997

//
// Xlib tutorial: 2nd program
// Make a window appear on the screen and draw a line inside.
// If you don't understand this program, go to
// http://tronche.lri.fr:8000/gui/x/xlib-tutorial/2nd-program-anatomy.html
//

#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds

#define NIL (0)       // A name for the void pointer

int main()
{
      Display *dpy = XOpenDisplay(NIL); // Open the display
      assert(dpy); //Checks if the dpy is null

      // Get some colors
      int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
      int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

      // Create the window
      Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 
				     200, 100, 0, blackColor, blackColor);

      XSelectInput(dpy, w, StructureNotifyMask); // We want to get MapNotify events
      XMapWindow(dpy, w); // "Map" the window (that is, make it appear on the screen)

      GC gc = XCreateGC(dpy, w, 0, NIL); // Create a "Graphics Context"

      XSetForeground(dpy, gc, whiteColor); // Tell the GC we draw using the white color

      // Wait for the MapNotify event
      for(;;) {
	    XEvent e;
	    XNextEvent(dpy, &e);
	    if (e.type == MapNotify)
		  break;
      }

      XDrawLine(dpy, w, gc, 10, 60, 180, 20); // Draw the line
      XFlush(dpy); // Send the "DrawLine" request to the server
      sleep(10); // Wait for 10 seconds
      return 0;

}

