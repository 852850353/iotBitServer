# Explain
   This is an Internet of things framework from the automotive industry, but not limited to the automotive industry. It is mainly used to analyze can protocol or some binary flows customized in work. Its processing flow is defined as the agreement in the Internet of things device is consistent with the requirements of the server, and has a detailed explanation for the bit bit bit of the protocol, such as deviceid and devicetype. This will also be the server's upper level representation in the stored data. This can better serve the platform of big data.This project is different from the server of character stream service, because the protocol is represented as binary, so we can use limited bandwidth resources, CPU resources and memory resources to do more things. This idea seems a bit crazy, but it originated from the way of Google's protocolbuf serialization. I believe you have used htons() function under Linux, which is a bit of a type.
# Requirement description
   1.The service adopts TCP protocol, and the upper layer is encapsulated as binary stream
   2.The efficiency of the server needs to reach ms level after data reporting to the server.
   3.Message subscription processing, similar to event driven
   4.The format is loaded as a custom binary stream flag. Of course, this can be in any format
   5.Default database support, database extension (asynchronous component) can be performed according to Item 4 in the later stage
   6.Own distributed support (call protocol is RPC)
   7.Encryption and decryption certificate and compression rules
