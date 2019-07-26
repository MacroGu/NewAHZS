/*
	author: Macro Gu
	email: macrogu@qq.com
	QQ: 877188891
*/

#pragma once

#include <string>
#include "base64.h"
#include "sha1.h"
#include "defines.h"
#ifdef _WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#endif

//Websocket���ݰ�����ͷ��Ϣ
struct WebSocketStreamHeader {
	unsigned int header_size;                //���ݰ�ͷ��С
	int mask_offset;                    //����ƫ��
	unsigned int payload_size;                //���ݴ�С
	bool fin;                                               //֡���
	bool masked;                            //����
	unsigned char opcode;                    //������
	unsigned char res[3];
};

// ���ݰ���������
enum WebSocketOpCode {
	ContinuationFrame = 0x0,                //����֡
	TextFrame = 0x1,						//�ı�֡
	BinaryFrame = 0x2,						//������֡
	ConnectionClose = 0x8,                  //���ӹر�
	Ping = 0x9,
	Pong = 0xA,
	EmptyFrame = 0xF0,
	ErrorFrame = 0xF1,
	OperingFrame = 0xF3,
	ClosingFrame = 0x08
};

class CWebSocketStyle
{
public:
	CWebSocketStyle();
	~CWebSocketStyle();


	// һЩ�����ж� ws ���ݸ�ʽ�ĺ���
public:
	// ����
	bool isWSHandShake(std::string &request);
	
	// ����ǣ���������Э��������װ׼��send�ظ���client
	bool wsHandshake(std::string &request, std::string &response);

	// ���Ƚ�����ͷ��Ϣ
	bool wsReadHeader(const unsigned char* cData, WebSocketStreamHeader* header);

	// Ȼ����ݰ�ͷ��������������
	bool wsDecodeFrame(const WebSocketStreamHeader& header, unsigned char cbSrcData[], unsigned short wSrcLen, unsigned char cbTagData[]);

	// ��װserver����clientЭ��
	bool wsEncodeFrame(std::string inMessage, std::string &outFrame, enum WebSocketOpCode frameType);

	// �����ͻ��� ���� string
	bool wsDecodeFrame(std::string inFrame, std::string& outMessage);

};
