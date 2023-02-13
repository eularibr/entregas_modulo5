#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Cliente[max_items];
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

//busca na tabela hash um cliente, retornando um booleano verdadeiro se houver o cliente, ou falso se o cliente não existir.
void Hash::retrieveItem(Cliente& cliente, bool& found) {
  int startLoc = getHash(cliente);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getImei() == cliente.getImei() ||
	structure[location].getImei() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);
  
  found = (structure[location].getImei() == cliente.getImei() );   
  if (found) { 
    cliente = structure[location];
  }
}

//método que insere um cliente na tabela, definindo sua posição.
void Hash::insertItem(Cliente cliente) {
  int location;
  location = getHash(cliente);
  while (structure[location].getImei() > 0)
    location = (location + 1) % max_items;
  structure[location] = cliente;
  length++;
}

//método que deleta um cliente da tabela.
void Hash::deleteItem(Cliente cliente) {
  int startLoc = getHash(cliente);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getImei() == cliente.getImei() ||
	structure[location].getImei() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getImei() == cliente.getImei()) {       
    structure[location] = Cliente(-2,"");
    length--;
  }
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getImei()<<", "<<structure[i].getLogin()<<endl;
  }
}

//função da tabela hash, que realiza a função mod a partir do número imei e de uma chave hash inserida.
int Hash::getHash(Cliente cliente){
  return cliente.getImei() % max_items;
}