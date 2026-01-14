class Solution: 
  """
  - make two sets seen and duplicates
  - loop through the list of integers
  - if current item exists in seen then add that to duplicates set
  - else add to seen set
  - return len(list(duplicates)) > 0
  """
  # time complexity: O(n)
  # space complexity: O(n)
  def hasDuplicate(self, nums: list[int]) -> bool:
    seen = set()
    duplicates = set()
    for item in nums:
      if item in seen:
        duplicates.add(item)
      else:
        seen.add(item)

    return len(list(duplicates)) > 0

  """
  - sort string s and t in ascending or descending order
  - if s == t return True else False
  """
  def isAnagram(self, s: str, t: str) -> bool:
    sorted_s = sorted(s)
    sorted_t = sorted(t)

    return sorted_s == sorted_t

  """
  - two loops for list (i and j indexes)
  - if item[i] + item[j] == target
  - result.add(i) result.add(j)
  - return list(result)
  """
  def twoSum(self, nums: list[int], target: int) -> list[int]:
    result: list(int) = []

    for i in range(len(nums)):
      for j in range(i+1, len(nums)):
        if nums[i] + nums[j] == target:
          result.append(i)
          result.append(j)

    return list(result)

  """
  - string -> lowercase + trim whitespaces + symbols (isalnum())
  - return string == string.reverse()
  """
  def isPalindrome(self, s: str) -> bool:
    s = "".join(char.lower() for char in s if char.isalnum())
    return s == s[::-1]

  """
  - for each ith day take it as a buy day
  - then compare it with all others to find the max for profit
  """
  def maxProfit(self, prices: list[int]) -> int:
    res = 0

    for i in range(len(prices)):
      buy = prices[i]
      for j in range(i + 1, len(prices)):
        sell  = prices[j]
        res = max(res, sell - buy)

    return res

  """
  - for chars in s
  - if char is any from ( [ or { append to list
  - otherwise if nothing in stack then return False
  - pop the stack (gives top)
  - if it doesn't match either of ) ] or } return False
  - finally return len(stack) == 0 (fulfils the condition of stack being empty if all values matched)
  """
  def isValid(self, s: str) -> bool:
    stack: list(str) = []

    for char in s:
      if char == '(' or char == '[' or char == '{':
        stack.append(char)
      else:
        if not stack:
          return False
        
        top = stack.pop()

        if char == ')' and top != '(' or char == ']' and top != '[' or char == '}' and top != '{':
          return False
    
    return len(stack) == 0

sol = Solution()

# 1. has duplicates
inp: list[int] = [1, 2, 3, 3]
print(sol.hasDuplicate(nums=inp))

# 2. valid anagram
s: list(str) = ["racecar", "jar"]
t: list(str) = ["carrace", "jam"]
print(sol.isAnagram(s=s[0], t=t[0]))
print(sol.isAnagram(s=s[1], t=t[1]))

# 3. two sum
nums: list(list(int)) = [[3, 4, 5, 6], [4, 5, 6], [5, 5]]
target: list(int) = [7, 10, 10]
print(sol.twoSum(nums=nums[0], target=target[0]))
print(sol.twoSum(nums=nums[1], target=target[1]))
print(sol.twoSum(nums=nums[2], target=target[2]))

# 4. valid palindrome
s: list(str) = ["Was it a car or a cat I saw?", "tab a cat"]
print(sol.isPalindrome(s[0]))
print(sol.isPalindrome(s[1]))

# 5. best time to buy and sell stock
prices: list(list(int)) = [[10, 1, 5, 6, 7, 1], [10, 8, 7, 5, 2]]
print(sol.maxProfit(prices[0]))
print(sol.maxProfit(prices[1]))

# 6. valid parentheses
s: list(str) = ["[]", "([{}])", "[(])"]
print(sol.isValid(s[0]))
print(sol.isValid(s[1]))
print(sol.isValid(s[2]))