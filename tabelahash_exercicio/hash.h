#include "cliente.h"

// propriedades da hash, como por exemplo, o número máximo da chave do hash
class Hash {
public:
  Hash(int max_items = 50);
  ~Hash();
  bool isFull() const;
  int getLength() const;

  // ações possíveis a se realizar com tabela hash (busca, inserção e remoção)
  void retrieveItem(Cliente &cliente, bool &found);
  void insertItem(Cliente cliente);
  void deleteItem(Cliente cliente);
  void print();

private:
  int getHash(Cliente cliente);
  int max_items;
  int length;
  Cliente *structure;
};
