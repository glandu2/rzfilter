#include "Core/EventLoop.h"
#include "GlobalConfig.h"
#include "LibRzuInit.h"
#include "Config/GlobalCoreConfig.h"
#include "Core/CrashHandler.h"
#include "Database/DbConnectionPool.h"

#include "NetSession/ServersManager.h"
#include "NetSession/BanManager.h"
#include "NetSession/SessionServer.h"
#include "AdminInterface.h"

#include "ClientSession.h"

void runServers(Log* trafficLogger);

void onTerminate(void* instance) {
	ServersManager* serverManager = (ServersManager*) instance;

	if(serverManager)
		serverManager->stop();
}

int main(int argc, char **argv) {
	LibRzuInit();
	GlobalConfig::init();

	ConfigInfo::get()->init(argc, argv);

	Log mainLogger(GlobalCoreConfig::get()->log.enable,
				   GlobalCoreConfig::get()->log.level,
				   GlobalCoreConfig::get()->log.consoleLevel,
				   GlobalCoreConfig::get()->log.dir,
				   GlobalCoreConfig::get()->log.file,
				   GlobalCoreConfig::get()->log.maxQueueSize);
	Log::setDefaultLogger(&mainLogger);

	Log trafficLogger(CONFIG_GET()->trafficDump.enable,
					  CONFIG_GET()->trafficDump.level,
					  CONFIG_GET()->trafficDump.consoleLevel,
					  CONFIG_GET()->trafficDump.dir,
					  CONFIG_GET()->trafficDump.file,
					  GlobalCoreConfig::get()->log.maxQueueSize);


	ConfigInfo::get()->dump();

	runServers(&trafficLogger);

	//Make valgrind happy
	EventLoop::getInstance()->deleteObjects();

	return 0;
}

void runServers(Log *trafficLogger) {
	ServersManager serverManager;

	SessionServer<ClientSession> clientSessionServer(
				CONFIG_GET()->client.listener.ip,
				CONFIG_GET()->client.listener.port,
				&CONFIG_GET()->client.listener.idleTimeout,
				trafficLogger);

	SessionServer<AdminInterface> adminTelnetServer(
				CONFIG_GET()->admin.listener.ip,
				CONFIG_GET()->admin.listener.port,
				&CONFIG_GET()->admin.listener.idleTimeout);


	serverManager.addServer("clients", &clientSessionServer, CONFIG_GET()->client.listener.autoStart);
	serverManager.addServer("admin.telnet", &adminTelnetServer, CONFIG_GET()->admin.listener.autoStart);

	serverManager.start();

	CrashHandler::setTerminateCallback(&onTerminate, &serverManager);

	EventLoop::getInstance()->run(UV_RUN_DEFAULT);

	CrashHandler::setTerminateCallback(nullptr, nullptr);
}
