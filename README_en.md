# Explain
   This is an Internet of things framework from the automotive industry, but not limited to the automotive industry. It is mainly used to analyze can protocol or some binary flows customized in work. Its processing flow is defined as the agreement in the Internet of things device is consistent with the requirements of the server, and has a detailed explanation for the bit bit bit of the protocol, such as deviceid and devicetype. This will also be the server's upper level representation in the stored data. This can better serve the platform of big data.This project is different from the server of character stream service, because the protocol is represented as binary, so we can use limited bandwidth resources, CPU resources and memory resources to do more things. This idea seems a bit crazy, but it originated from the way of Google's protocolbuf serialization. I believe you have used htons() function under Linux, which is a bit of a type.
# Requirement description
   1. The service adopts TCP protocol, and the upper layer is encapsulated as binary stream
   2. The efficiency of the server needs to reach ms level after data reporting to the server.
   3. Message subscription processing, similar to event driven
   4. The format is loaded with a custom binary stream flag. Of course, it can be in any format. This method can translate the bit meaning of the upper layer, which is equivalent to the second level cache processing
   5. Default database support, database extension (asynchronous component) can be performed according to item 4 in the later stage
   6. Own distributed support (call protocol is RPC)
   7. Encryption and decryption certificate and compression rules
   
 # Infrastructure
   ![BaseFramework](https://github.com/armFunNing/iotBitServer/blob/master/BaseFramework.png)

 # Project-tree
	./
	├── 3rdparty					Third-party libraries
	├── cmake
	├── CMakeLists.txt
	├── CMakeLists.txt.user
	├── docs
	├── examples
	├── iotAlive					Server node alive widget, to use RPC or Thrift connection framework
	├── iotBaseProtocol				Base connection class, from package TCP/UDP/HTTP protocol 3rdparty
	├── iotCore						Server core framework,The register function subscribes to the message
	├── iotFileIO					Definitions configuration files  class and more.
	├── iotMemory					Memory manager server
	├── iotModel				    Upper configuration module, eg:Compression library(zlib)、Check the library(CRC)
	├── iotTimeDB					A chronological database encapsulates class and so on
	├── iotTools					A user-friendly tool, such as a back-end service client from Qt
	├── test						An internal test module from the developer
	├── en_README.md
	└── zh_README.md

	13 directories, 5 files