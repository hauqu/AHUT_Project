# 此处为游戏服务端测试程序的结构说明

opencv 4.5.0 
## 服务端：
	数据流方向
	从 ip1 获得控制字符 
	格式为 玩家标签 原棋子类型 目标棋子类型 ，如 1 1  
	服务器运算 返回 运算结果
	格式为 玩家标签 棋子类型 


### 流程
	1.启动 服务，准备接受连接 ，
	接受连接1，接受连接2
	创建房间 ，将玩家加入
	开始游戏
	接受和返还数据
##客户端1：
	所有改变需要获得服务端允许才能成功
### 流程
	1.启动服务 ，寻找服务器，建立连接
	加入房间，开始游戏
##客户端2：