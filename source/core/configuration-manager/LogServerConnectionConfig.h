#ifndef LOG_SERVER_CONNECTION_CONFIG_H_
#define LOG_SERVER_CONNECTION_CONFIG_H_

#include <string>

namespace sf1r
{

struct LogServerConnectionConfig
{
public:
    std::string host;
    unsigned int rpcPort;
    unsigned int rpcThreadNum;
    unsigned int driverPort;

    LogServerConnectionConfig(
        const std::string& host_addr = "localhost",
        unsigned int rpc_port = 0,
        unsigned int rpc_thread_num = 10,
        unsigned int driver_port = 0
    )
        : host(host_addr)
        , rpcPort(rpc_port)
        , rpcThreadNum(rpc_thread_num)
        , driverPort(driver_port)
    {}
};

} // namespace sf1r

#endif //LOG_SERVER_CONNECTION_CONFIG_H_
