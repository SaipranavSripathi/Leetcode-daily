class NumberContainers {
    public:
        // Constructor
        // The data structures are already initialized as
        // part of the member variable declarations.
        NumberContainers() {}
    
        void change(int index, int number) {
            if (indexToNumbers.find(index) != indexToNumbers.end()) {
                int previousNumber = indexToNumbers[index];
                numberToIndices[previousNumber].erase(index);
                if (numberToIndices[previousNumber].empty()) {
                    numberToIndices.erase(previousNumber);
                }
            }
            indexToNumbers[index] = number;
            numberToIndices[number].insert(index);
        }
    
        int find(int number) {
            if (numberToIndices.find(number) != numberToIndices.end()) {
                // Get the smallest index
                return *numberToIndices[number].begin();
            }
            return -1;
        }
    
    private:
        // Map from number to set of indices
        unordered_map<int, set<int>> numberToIndices;
        // Map from index to number
        unordered_map<int, int> indexToNumbers;
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */