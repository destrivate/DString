#include <iostream>

using namespace std;

class DString{
    private:
        char* data;
        int capacity;
        int size;  
        void ensureCapacity(){
            if(size == capacity){return;}
            capacity = size * 2;
            char* newData = new char[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            newData[size] = '\0'; 
            delete[] data;
            data = newData;
        }
    public:
        DString(const char* str){
            int len = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                len++;
            }
            size = len;
            capacity = size + 1;
            data = new char[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = str[i];
            }

            data[size] = '\0';   
        }
        ~DString(){
            delete[] data;
        }
        int getSize(){
            return size;
        }
        char* c_str(){
            return data;
        }
        void replace(const char& oldV,const char& newV){
            for(int i = 0;i < size;i++){
                if(data[i] == oldV){
                    data[i] = newV;
                }
            }
        }
        void add(const char* value){        
            int len = 0;
            while(true){
                if(value[len] == '\0'){
                    break;
                }
                len++;
            }
            int oldSize = size;
            size += len;
            ensureCapacity();
            for(int i = 0;i<len;i++){
                data[oldSize+i] = value[i];
            }
            data[size] = '\0';
        }
};

int main() {
    DString name = "This is DString!";
    cout << name.c_str() << endl;
    name.add("Added text");
    cout << name.c_str() << endl;
    name.replace('T','D');
    cout << name.c_str() << endl;
    return 0;
}
