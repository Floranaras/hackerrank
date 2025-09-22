import random

def quickselect_kth_largest(arr, k):
    if not arr or k > len(arr) or k <= 0:
        return -1
    
    target = len(arr) - k
    
    def partition(left, right, pivot_idx):
        pivot_val = arr[pivot_idx]
        arr[pivot_idx], arr[right] = arr[right], arr[pivot_idx]
        
        store_idx = left
        for j in range(left, right):
            if arr[j] <= pivot_val:  
                arr[store_idx], arr[j] = arr[j], arr[store_idx]
                store_idx += 1
        
        arr[right], arr[store_idx] = arr[store_idx], arr[right]
        return store_idx
    
    def select(left, right, target):
        if left == right:
            return arr[left]
        
        pivot_idx = random.randint(left, right)
        pivot_idx = partition(left, right, pivot_idx)
        
        if target == pivot_idx:
            return arr[target]
        elif target < pivot_idx:
            return select(left, pivot_idx - 1, target)
        else:
            return select(pivot_idx + 1, right, target)
    
    return select(0, len(arr) - 1, target)

def main():
    n = int(input())
    vals = []
    
    for _ in range(n):
        r, c = map(int, input().split())
        vals.append(r - c)  
    
    q = int(input())
    
    for _ in range(q):
        s, e, A, K = map(int, input().split())
        
        if s > e:
            s, e = e, s
        
        tickets = A // K
        if tickets <= 0:
            print(-1)
            continue
        
        range_size = e - s + 1
        tickets = min(tickets, range_size)
        
        subarray = vals[s:e+1]
        
        ans = quickselect_kth_largest(subarray[:], tickets)  # Copy to avoid modifying
        print(ans)

if __name__ == "__main__":
    main()
