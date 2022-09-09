# import socket

# client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client_socket.connect(("127.0.0.1", 5000))
# while 1:
#     data = client_socket.recv(512).decode()
#     if ( data == 'q' or data == 'Q'):
#         client_socket.close()
#         break
#     else:
#         print ("RECEIVED:" , data)
#         data = input ( "SEND( TYPE q or Q to Quit):" )
#         if ( data == 'q' or data == 'Q'):
#             client_socket.send(data.encode())
#             client_socket.close()
#             break
#         else:
#             client_socket.send(data.encode())
# print ("socket colsed... END.")

import socket
import time


# sock.connect(('127.0.0.1', 9000))
# sock.send('hello'.encode())
while 1:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # sock.bind(('127.0.0.1', 9000))
    try:
        sock.connect(('127.0.0.1', 9000))
        data = sock.recv(256)
        print(data.decode("utf-8"))
    except:
        # print('fail to connect socket')
        pass
    sock.close()
    # time.sleep(0.1)