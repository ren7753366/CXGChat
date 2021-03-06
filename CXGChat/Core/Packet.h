#ifndef __PACKET_H_
#define __PACKET_H_

#include "RefCount.h"

typedef unsigned char PACKET_TYPE;

#pragma pack(push, 1)

struct PACKET_HADER
{
	int packetSize;
    char packetAction;
    char packetType;
    short packetBaoliu;
};

#pragma pack(pop)

// CPacket
class CPacket
	: public CRefCount
{
public:
	static CPacket* CreateFromPayload(char* pPayload, int nPayload);
	static CPacket* CreateFromTotal(char* pTotal, int nTotal);

    void SetPacketType(int ptType);
    int GetPacketType() const;
	int GetPacketSize() const;
	char* GetPayload() const;
	int GetPayloadSize() const;
	char* GetTotal() const;
	int GetTotalSize() const;
    void SetPacketAction(int ptAction);

protected:
	CPacket();
	virtual ~CPacket();
	bool InitPayload(char* pPayload, int nPayload);
	bool InitTotal(char* pTotal, int nTotal);

private:
	PACKET_HADER*    m_pHeader;
	char*            m_pTotal;
	long              m_nTotal;
	char*            m_pPayload;
	long              m_nPayload;
};

#endif
