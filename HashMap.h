#ifndef HASHMAP_H
#define HASHMAP_H

/* Handle association */
template<typename hash,typename map>
class HashType {
    public:
        HashType(){ 
            reset(); 
        }
        
        HashType(hash code,map value):hashCode(code),mappedValue(value){}
        
        void reset(){ 
            hashCode = 0; 
            mappedValue = 0; 
        }
        
        hash getHash(){ 
            return hashCode;
        }
        
        void setHash(hash code){ 
            hashCode = code;
        }
        
        map getValue(){ 
            return mappedValue; 
        }
        
        void setValue(map value){
            mappedValue = value; 
        }
        
        HashType& operator()(hash code, map value){
            setHash(code);
            setValue(value);
        }
    
    private:
        hash hashCode;
        map mappedValue;
};

/*
Handle indexing and searches
*/
template<typename hash,typename map>
class HashMap {
    public:
        //deprecated constructor
        HashMap(HashType<hash,map>* newMap,uint8_t newSize){
            hashMap = newMap;
            size = newSize;
            for (uint8_t i=0; i<size; i++){
                hashMap[i].reset();
            }
        }

        HashMap(uint8_t newSize) {
            hashMap = new HashType<hash,map>[newSize];
            size = newSize;
            for (uint8_t i=0; i<size; i++){
                hashMap[i].reset();
            }
        }

        ~HashMap() {
          delete(hashMap);
        }
        
        HashType<hash,map>& operator[](uint8_t x){
            return hashMap[x%size];
        }
        
        uint8_t getIndexOf(hash key){
            for (uint8_t i=0; i<size; i++){
                if (hashMap[i].getHash()==key){
                    return i;
                }
            }
        }
        
        map getValueOf(hash key){
            for (uint8_t i=0; i<size; i++){
                if (hashMap[i].getHash()==key){
                    return hashMap[i].getValue();
                }
            }
        }

        uint8_t getSize() {
            return size;
        }
        
        void debug(){
            for (uint8_t i=0; i<size; i++){
                Serial.print(hashMap[i].getHash());
                Serial.print(" - ");
                Serial.println(hashMap[i].getValue());
            }
        }
        
    private:
        HashType<hash,map>* hashMap;
        uint8_t size;
};

#endif
