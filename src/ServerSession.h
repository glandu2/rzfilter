#ifndef AUTHSESSION_H
#define AUTHSESSION_H

#include "NetSession/EncryptedSession.h"
#include "NetSession/PacketSession.h"
#include "IFilterEndpoint.h"

class ClientSession;

class ServerSession : public EncryptedSession<PacketSession>, public IFilterEndpoint
{
	DECLARE_CLASS(ServerSession)
public:
	ServerSession(ClientSession* clientSession);
	~ServerSession();

	void connect();

	void onConnected();
	void onDisconnected(bool causedByRemote);

	void sendPacket(const TS_MESSAGE* message);

protected:
	void onPacketReceived(const TS_MESSAGE* packet);

private:
	using SocketSession::connect;

	ClientSession* clientSession;

	std::vector<TS_MESSAGE*> pendingMessages;
};

#endif // AUTHSESSION_H
