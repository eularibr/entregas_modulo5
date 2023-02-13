#include "hash.h"
#include <iostream>

using namespace std;

// Casos de teste
int main() {
  // Caso 1: Inserção de imeis e logins na tabela hash em dois arrays
  Hash clientesHash(50);
  int imeis[8] = {12704, 313007, 12345, 49001, 52202, 65606, 91234, 91234};
  string emails[8] = {"pedro11@gmail.com",   "raul22@gmail.com",
                      "paulo33@gmail.com",   "carlos44@gmail.com",
                      "lucas55@gmail.com",   "maria66@gmail.com",
                      "samanta77@gmail.com", "mario88@gmail.com"};
  for (int i = 0; i < 8; i++) {
    Cliente cliente = Cliente(imeis[i], emails[i]);
    clientesHash.insertItem(cliente);
  }
  clientesHash.print();
  cout << "------------------------------" << endl;

  // Caso 2: Busca um cliente a partir do seu imei
  Cliente cliente(12704, "");
  bool found = false;
  clientesHash.retrieveItem(cliente, found);
  cout << cliente.getLogin() << " -> " << found << endl;
  cout << "------------------------------" << endl;

  // Caso 3: Deleta um cliente que existe na tabela, como o imei dado acima foi
  // o do pedro11@gmail.com, esse foi o cliente deletado da tabela. Na posição
  // 4, ficou o -2.
  clientesHash.deleteItem(cliente);
  clientesHash.print();
  cout << "Fim" << endl;
  cout << "------------------------------" << endl;

  // Caso 4: Deleta um cliente que não existe na tabela
  Cliente cliente2(823567, "");
  bool found2 = false;
  clientesHash.retrieveItem(cliente2, found2);
  cout << cliente2.getLogin() << " -> " << found2 << endl;
  cout << "------------------------------" << endl;

  // Caso 5: Inserção de um único novo cliente
  Cliente novoCliente = Cliente(100404, "larissa10@gmail.com");
  clientesHash.insertItem(novoCliente);
  clientesHash.print();
  return 0;
}
