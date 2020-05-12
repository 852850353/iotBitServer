# 说明
   这是一个来自汽车行业的物联网框架，但不限于汽车行业。
   它主要用于分析工作中定制的can协议或一些二进制流。
   其处理流程定义为物联网设备中的协议符合服务器的要求，并对协议的位比特位进行了详细的说明，如deviceid和devicetype。
   这也将是存储数据中服务器的上层表示。这可以更好的服务于大数据平台。
   这个项目不同于字符流服务的服务器，因为协议是用二进制表示的，所以我们可以使用有限的带宽资源、CPU资源和内存资源来做更多的事情。
   这个想法看起来有点疯狂，但是它起源于谷歌协议序列化的方式。我相信您已经在Linux下使用了htons()函数，这是一种二进制的格式。
# 前期需求
	1. 服务采用TCP协议，上层封装为二进制流
	2. 数据向服务器报告后，服务器的效率需要达到ms级。
	3. 消息订阅处理，类似于事件驱动
	4. 该格式使用自定义的二进制流标记加载。当然，它可以是任何格式。该方法可以翻译上层的位含义，相当于第二层缓存处理
	5. 默认数据库支持，后期可根据item 4执行数据库扩展(异步组件)
	6. 自己的分布式支持(调用协议是RPC)
	7. 加密和解密证书和压缩规则
   
 # 基础架构
   ![BaseFramework](https://github.com/armFunNing/iotBitServer/blob/master/BaseFramework.png)
 
 # 工程树
		./
	├── 3rdparty					第三方库
	├── cmake
	├── CMakeLists.txt
	├── CMakeLists.txt.user
	├── docs
	├── examples
	├── iotAlive					运用RPC或者Thrift缔造的服务结点组件
	├── iotBaseProtocol				封装TCP/UDP/HTTP协议的基础连接类
	├── iotCore						服务内核框架，用于注册消息订阅
	├── iotFileIO					一些配置文件类
	├── iotMemory					内存管理模块
	├── iotModel				    上层配置模块，例如:压缩库(zlib)，检查库(CRC)
	├── iotTimeDB					按时间顺序排列的数据库封装类等等
	├── iotTools					一个用户友好的工具，例如来自Qt的后端服务客户端
	├── test						开发人员提供的内部测试模块
	├── en_README.md
	└── zh_README.md