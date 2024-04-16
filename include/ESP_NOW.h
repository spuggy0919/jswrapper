class ESP_NOW_Class : public Print {
public:
  const uint8_t BROADCAST_ADDR[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

  ESP_NOW_Class();
  ~ESP_NOW_Class();

  bool begin(const uint8_t *pmk = NULL /* 16 bytes */);
  bool end();

  int getTotalPeerCount();
  int getEncryptedPeerCount();

  int availableForWrite();
  size_t write(const uint8_t *data, size_t len);
  size_t write(uint8_t data) {
    return write(&data, 1);
  }

  void onNewPeer(void (*cb)(const esp_now_recv_info_t *info, const uint8_t *data, int len, void *arg), void *arg);
};