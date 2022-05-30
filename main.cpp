/*NAMA = Tyas Awalin Nisa Magfiroh*/
/*NIM  = 1121031080*/
/*TUGAS STRUKTUR DATA PROGRAM DLLC HEAD & TAIL */
#include <iostream>
using namespace std;

struct TNode {
    int data;       // field data
    int key;
    TNode *next;    // field pointer next
    TNode *prev;    // field pointer prev
};

TNode *head, *tail; // deklarasi variabel pointer head untuk menunjukkan kepala node

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
    } else {
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
        head->prev = tail;
        tail->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        head->prev = head;
        tail->next = head;
        tail->prev = head;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
        tail->next = head;
        head->prev = tail;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus;
    int d;

    if (isEmpty() == 0) {
        if (head != tail) {
            nodeHapus = head;
            d = nodeHapus->data;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head != head) {
            nodeHapus = tail;
            d = nodeHapus->data;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void deleteNode(TNode** head_ref, int key)
{
    TNode* temp = *head_ref;
    TNode* prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
        else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    prev->next = temp->next;

    delete temp;
    }
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        do {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != head);
    } else {
        cout << "List masih kosong" << endl;
    }
}
void search(int searchValue){
    TNode *temp = head;
    int found = 0;
    int i = 0;

    if(temp != NULL) {
        while(temp != NULL) {
          i++;
          if(temp->data == searchValue) {
            found++;
            break;
          }
          temp = temp->next;
        }
        if (found == 1) {
          cout<<searchValue<<" is found at index = "<<i<<".\n";
        } else {
          cout<<searchValue<<" is not found in the list.\n";
        }
      } else {
        cout<<"The list is empty.\n";
      }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;
    nodeBantu = head;

    while (nodeBantu->next != head) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        delete nodeHapus;
    }

    head = NULL;
    cout << "Linked List kosong\n";
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ==================================="<<endl;
        cout<<" =    PROGRAM DLLC HEAD & TAIL     ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" = 1. Insert Depan                 ="<<endl;
        cout<<" = 2. Insert Belakang              ="<<endl;
        cout<<" = 3. Hapus Depan                  ="<<endl;
        cout<<" = 4. Hapus Belakang               ="<<endl;
        cout<<" = 5. Tampil Data                  ="<<endl;
        cout<<" = 6. Cari Data                    ="<<endl;
        cout<<" = 7. Hapus semua Data             ="<<endl;
        cout<<" = 8. Hapus Data                   ="<<endl;
        cout<<" = 9. Exit                         ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if (pil == 1) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertDepan(dataBaru);
        } else if (pil == 2) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertBelakang(dataBaru);
        } else if (pil == 3) {
            hapusDepan();
        } else if (pil == 4) {
            hapusBelakang();
        } else if (pil == 5) {
            tampilData();
        }else if (pil == 6) {
            cout<< "Masukan Data yang dicari :";
            cin>>dataBaru;
            search(dataBaru);
        } else if (pil == 7) {
            hapusSemua();
        }else if (pil == 8) {
            cout<< "Masukan Data yang ingin dihapus :";
            cin>>dataBaru;
            deleteNode(&head, dataBaru);
        } else if (pil != 9) {
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
    } while (pil != 9);

    return 0;
}
/*NAMA = Tyas Awalin Nisa Magfiroh*/
/*NIM  = 1121031080*/
/*TUGAS STRUKTUR DATA PROGRAM DLLC HEAD & TAIL */
