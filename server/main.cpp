/*
	author: Macro Gu
	email: macrogu@qq.com
	QQ: 877188891
*/


#include "MGServer.h"
#include <iostream>
#include "gtest/gtest.h"
#include "ServerConf.h"
#include "RedisHandle.h"
#include "DataBaseOp.h"


// Single test to discover
TEST(serverConf, serverInitial)
{
	// ���ط�����������
	EXPECT_TRUE(ServerConf::GetInstance().LoadServerConf());
	// redis �ĳ�ʼ�� 
	EXPECT_TRUE(RedisHandle::GetInstance().Init());
	// DataBase �ĳ�ʼ�� 
	EXPECT_TRUE(DataBaseOp::GetInstance().Init());
}

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// �����ʽ���У���Ҫ������Ĵ���
// int  main(int argc, char ** argv) {
// 
// 	MGServer acceptServer;
// 
// 	acceptServer.StartServer();
// 
// 	return 0;
// 
// }
