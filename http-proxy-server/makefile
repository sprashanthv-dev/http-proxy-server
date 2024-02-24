all:
	gcc -Wno-deprecated-declarations proxy.c -o proxy ./websocket.c ./error_utils.c ./req_handler.c ./utils.c ./res_handler.c ./file_ops.c ./dns_cache.c ./blacklist.c ./page_cache.c ./dir_ops.c -lssl -lcrypto

clean:
	rm -rf ./proxy