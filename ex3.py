def fibonaccico(array, n): 
    hashTable = set(array)  
    maxSubSequence = 0
  
    for i in range(0, n):  
        for j in range(i + 1, n):  
            
            # assumes the first and second are in the subsequence
            first = array[j]  
            second = array[i] + array[j]  
            currentSubSequence = 2
            
            # finds the next element in the subsequence
            while second in hashTable:  
                third = first + second
                first = second  
                second = third 
                # updates the new subsequence if it's bigger
                currentSubSequence += 1
                maxSubSequence = max(maxSubSequence, currentSubSequence)  
              
    # no subsequence found in the given array              
    if maxSubSequence < 3: 
        return 0

    else:
        return maxSubSequence

def main():
    n = int(input())
    integers = input()
    array = [int(i) for i in integers.split()]   
    
    print(fibonaccico(array, n))  
  
if __name__ == "__main__": 
    main()