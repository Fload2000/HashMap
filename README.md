# Overview

This is a HashMap library for the Arduino Platform. It is created to help simplify associating a key with a value. Or more abstract one value with another one.   
But this is **not** a real hashmap, it's a key-value-map. Searching in this `HashMap` is done via simple iteration over all entries, not via hashed-key. The reason for that is, that it should run on micro controllers such as Arduinos.  
This was inspired and based on [this HashMap](https://playground.arduino.cc/Code/HashMap/) library for Arduino by Alexander Brevig.

# Download, install and import

1. Download the library ([here](https://github.com/Fload2000/HashMap/archive/master.zip))
2. Extract the archive to `hardware\libraries\`
3. In the Arduino IDE, create a new sketch (or open one) and select from the menubar `Sketch->Import Library->HashMap`  
   Once the library is imported, an `#include <HashMap.h>` line will appear at the top of your Sketch. 

# Functions

### byte getIndexof( key )
Will return the index of the *key*.

### value getValueOf( key )
Will return the value associated to *key*

### byte getSize()
Will return the size of the HashMap.


# Example

```cpp
#include <HashMap.h>

// define the max size of the hashtable
const byte SIZE = 8;

// Initialize the hashmap with the two datatypes and the max size
HashMap<char*,int> hashMap = HashMap<char*,int>(SIZE);

void setup(){
    // setup hashmap
    hashMap[0]("name", 18);
    hashMap[1]("test", 200);
    hashMap[2]("qwer", 1234);
    hashMap[3]("abc", 123);
    hashMap[4]("AlphaBeta", 20);
    hashMap[5]("asdf", 456);
    hashMap[6]("wasd", 1337);
    hashMap[7]("hello", 1);

    // Initialize serial communication
    Serial.begin(9600);

    // Get the index of a key
    Serial.println(hashMap.getIndexOf("test"), DEC);
    // Get the Value of a key
    Serial.println(hashMap.getValueOf("test"));

    // Debug output of the hashmap -> prints out every pair
    hashMap.debug();
}

void loop(){
    // empty loop
}
```


# License

```
MIT License

Copyright (c) 2019 Fload

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```


# FAQ

```
//contact me
```

