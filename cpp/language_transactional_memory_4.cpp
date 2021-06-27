/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_transactional_memory_4.exe ./cpp/language_transactional_memory_4.cpp && (cd ../_build/cpp/;./language_transactional_memory_4.exe)
https://en.cppreference.com/w/cpp/language/transactional_memory
*/
std::atomic<bool> rehash{false};
// maintenance thread runs this loop
void maintenance_thread(void*) {
    while (!shutdown) {
        synchronized {
            if (rehash) {
                hash.rehash();
                rehash = false;
            }
        }
    }
}
// worker threads execute hundreds of thousands of calls to this function 
// every second. Calls to insert_key() from synchronized blocks in other
// translation units will cause those blocks to serialize, unless insert_key()
// is marked [[optimize_for_synchronized]]
[[optimize_for_synchronized]] void insert_key(char* key, char* value) {
  bool concern = hash.insert(key, value);
  if (concern) rehash = true;
}

