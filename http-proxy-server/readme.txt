CSCI 5273/ECEN 5273 Network Systems - Programming Assignment 3 (HTTP Proxy Server)

Introduction:

The program acts as a HTTP based proxy server sitting in the middle between the client and requested remote server.
It parses the incoming HTTP/1.0 (or) HTTP/1.1 client request, creates a new connection through a socket to the
requested resource and relays the response back from the server to the client through itself. Caching, blacklisting 
of specific domain names and IP addresses and prefetching of links in the background are also supported.

Design Decisions:

1. Relaying of requests through the proxy server:

    - Incoming client request is parsed and a new TCP socket is created to contact the requested remote server.
    - Once the remote server accepts the connection of the proxy server, it starts sending the requested resource.
    - The bytes from the remote server are received in chunks of 2048 bytes at the proxy server.
    - As and when each chunk is received, it is sent back to the original client.
    - All of the above steps are performed by multiple threads at the same time, each fetching a particular resource.
    - This ensures that the process is quicker and the client need not wait for a long time.

2. Page caching

    - Before contacting the remote server the requested resource is checked for its existence in the proxy cache.

    - If it exists, it is directly returned thereby avoiding the need to create a new connection to the remote server.

    - If not, once the response arrives the requested resource name is hashed using md5 and the file contents are
      written to this hashed value as its file name.

    - Using hashing simplifies the process of checking the existence of the resource since the same resource URL will
      always hash to the same value.

3. Host IP name caching

    - To get the remote server info, a DNS resolution is needed.
    - As soon as a host is resolved, the host name and IP address are recored in the "hostname_ip.txt" file.
    - Whenever host resolution needs to be done, the host name is first checked in this file.
    - If it exists, the DNS resolution is skipped and the socket info is built from this information.

4. Domain and IP based blocklisting

    - A list of host and IP names are specified as comma separated values in blacklist.txt
    - The requested resource is first checked in this file.
    - If a match is found, the request is immediately blocked by sending a 403 Forbidden Response.
    - If not the request proceeds as usual.

5. Prefetching

    - A separate thread is maintained for actively fetching embedded links in the background of the requested
      resource.

    - This is also stored in the cache so that it can be immediately sent back to the client on request, thereby
      avoiding contacting the remote server.

Build and Execution Steps:

The execution environment is assumed to Unix/Linux based.

    - Navigate to the project root and change directory to the http_web_proxy folder

    - From this folder, execute make all or just make

    - The above step compiles the necessary files and dependencies and produces the 
      executable named server respectively in the same http_web_proxy folder.

    - To run the program, execute ./proxy <PORT_NO> from a terminal (e.g.) ./proxy 5001

    - To test the functionality, either use netcat or the web browser as the client. The based
      url will be localhost or 127.0.0.1 followed by the port number used in the above step.

References and Citations:

My own http web server implementation code from Programming Assignment 2 (Major portion of that code is used here)

https://stackoverflow.com/questions/4217037/catch-ctrl-c-in-c
https://www.gnu.org/software/libc/manual/html_node/Closing-a-Socket.html
https://cboard.cprogramming.com/c-programming/81901-parse-url.html
https://stackoverflow.com/questions/7500892/get-index-of-substring
https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
https://stackoverflow.com/questions/6679204/how-to-get-substring-in-c
https://stackoverflow.com/questions/62059123/counting-the-number-of-lines-in-a-txt-file-in-c
https://stackoverflow.com/questions/791982/determine-if-a-string-is-a-valid-ipv4-address-in-c
https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
https://stackoverflow.com/questions/12510874/how-can-i-check-if-a-directory-exists
https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c
https://stackoverflow.com/questions/26620388/c-substrings-c-string-slicing
https://stackoverflow.com/questions/58065208/calculate-md5-in-c-display-output-as-string