def subarraysWithKDistinct(nums: list[int], k: int) -> int:
    n_subarr = 0
    for i in range(len(nums)):
        subarr = {nums[i]}
        n_diff = 1
        for j in range(i+1, len(nums)):
            
            if n_diff < k:
                if not nums[j] in subarr:
                    n_diff += 1
                    subarr.add(nums[j])
            elif n_diff == k:
                if not nums[j] in subarr:
                    break
                n_subarr += 1
        if n_diff == k:
            n_subarr += 1
            
                

    return n_subarr


def main():
    # debug and test
    print(subarraysWithKDistinct([1,2], 1))
    print(subarraysWithKDistinct([1,2,1,2,3], 2))
    print(subarraysWithKDistinct([1,2,1,3,4], 3))

main()