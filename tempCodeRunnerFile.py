    for i in range(len(nums)-1):
        subarr = [nums[i]]
        n_diff = 1
        for j in range(i+1, len(nums)):
            if n_diff < k:
                if not nums[j] in subarr:
                    n_diff += 1
                subarr.append(nums[j])
            elif n_diff == k:
                if nums[j] in subarr:
                    subarr.append(nums[j])
                    n_subarr += 1
                else:
                    break