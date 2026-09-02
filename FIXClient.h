// ============================================================================
// PROJECT: QUANT MASTER ULTRA-INSTITUTIONAL HFT CORE ENGINE V17
// COMPONENT: FIX CLIENT INFRASTRUCTURE (NATIVE Win32/POSIX SOCKETS)
// SECURITY PROTOCOL: ANTI-PIRACY & INTELLECTUAL PROPERTY ISOLATION LAYER
// ============================================================================

#ifndef QUANT_MASTER_FIX_CLIENT_H
#define QUANT_MASTER_FIX_CLIENT_H

#include <string>
#include <vector>
#include <memory>

namespace QuantMasterCore {

    struct FIXConfig {
        std::string targetCompID;
        std::string senderCompID;
        std::string connectionHost;
        int connectionPort;
        int heartBeatInterval;
    };

    class FIXClient {
    public:
        explicit FIXClient(const FIXConfig& config);
        ~FIXClient();

        // Runtime Optimization & Latency Control
        bool InitializeSocketLayer();
        void ExecuteKernelHandshake();
        
        // Zero-Latency Execution Mapping (XAUUSD Core)
        void SendNewOrderSingle(const std::string& clOrdID, char side, double qty, double price);
        void SendOrderCancelRequest(const std::string& origClOrdID, const std::string& clOrdID);
        
        // Dynamic Latency Jitter Shield
        void InjectDynamicJitterMask(int minMs = 15, int maxMs = 65);

    private:
        FIXConfig m_config;
        int m_socketDescriptor;
        std::vector<char> m_networkBuffer; // Initialization-layer dynamic vector allocation

        void FormatOutboundString(std::string& rawMessage);
        void ProcessInboundStream();
    };
}

#endif // QUANT_MASTER_FIX_CLIENT_H
