#include <stdio.h>
#include <fcgiapp.h>
#include "fcgi_stdio.h"

int main() {
    while (FCGI_Accept() > -1) {
        printf(
        "Content-type: text/html\nStatus: 200 OK\n"
        "\n"
        "<title>Hello World!</title>"
        "<h1>Hello World!</h1>");
    }

    return 0;
}
