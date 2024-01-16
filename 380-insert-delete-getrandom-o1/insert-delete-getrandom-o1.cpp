class RandomizedSet {
private:
    std::unordered_map<int, int> mymap;
    std::vector<int> list;
public:
    RandomizedSet() {
        // *The constructor should initialize the member variables.*
        //* No need to redeclare them here.*
    }
    
    bool insert(int val) {
        //*if value already exist*
        if(mymap.count(val)!= 0) return false;

        //*if not insert the val to map with value(index of list)*
        mymap[val] = list.size(); 

        //*add the value to list aswell*
        list.push_back(val); 
        return true;
    }
    
    bool remove(int val) {
        // *Check if the value exists in the map*
        if(mymap.count(val)!=0)
        {
            // *Get the index of the value in the list*
            int index = mymap[val]; 

            // *Swap the value to be removed with the last value in the list*
            int lastvalue = list.back();  //* Get the last value*

            //* Replace the value at the given index with the last value*   
            list[index] = lastvalue; 

            list.pop_back(); //* Remove the last element from the list*

            // *Update the index of the last value in the map to reflect its new position*
            mymap[lastvalue] = index;

            //* Remove the value from the map*
            mymap.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        int randomIndex = std::rand() % list.size();
        return list[randomIndex];
    }
};