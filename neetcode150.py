from typing import Optional
from typing import List

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

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
  def hasDuplicate(self, nums: List[int]) -> bool:
    seen = set()
    duplicates = set()
    for item in nums:
      if item in seen:
        duplicates.add(item)
      else:
        seen.add(item)

    return len(duplicates) > 0

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
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    result: List[int] = []

    for i in range(len(nums)):
      for j in range(i+1, len(nums)):
        if nums[i] + nums[j] == target:
          result.append(i)
          result.append(j)

    return result

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
  def maxProfit(self, prices: List[int]) -> int:
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
    stack: List(str) = []

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

  """
  - check value in center of list
  - if target is lower search the left half of list
  - if target is higher search the right half of list
  - continue above steps until target value is found OR until search area is empty
  - if found return index else return -1
  """
  def search(self, nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1

    while left <= right:
      mid = (left + right) // 2

      if nums[mid] == target:
        return mid
      
      if nums[mid] < target:
        left = mid+1
      else:
        right = mid-1
    
    return -1
  
  """
  - if head is not provided return None
  - set new_head = head
  - if next head exists then mark new head as output of new head
  - set head.next.next = head
  - finally set head.next = None (if head.next doesn't exist)
  - return new_head
  """
  def reverseList(self, head: Optional[ListNode]) -> Optional(ListNode):
    prev = None
    curr = head

    while curr:
      temp = curr.next
      curr.next = prev
      prev = curr
      curr = temp

    return prev

def build_linked_list(arr) -> Optional[ListNode]:
  dummy = ListNode()
  curr = dummy
  for x in arr:
    curr.next = ListNode(x)
    curr = curr.next
  return dummy.next

def linked_list_to_list(head) -> Optional[List]:
  res = []
  while head:
    res.append(head.val)
    head = head.next
  return res

sol = Solution()

# 1. has duplicates
inp: List[int] = [1, 2, 3, 3]
print(sol.hasDuplicate(nums=inp))

# 2. valid anagram
s: List(str) = ["racecar", "jar"]
t: List(str) = ["carrace", "jam"]
print(sol.isAnagram(s=s[0], t=t[0]))
print(sol.isAnagram(s=s[1], t=t[1]))

# 3. two sum
nums: List(List(int)) = [[3, 4, 5, 6], [4, 5, 6], [5, 5]]
target: List(int) = [7, 10, 10]
print(sol.twoSum(nums=nums[0], target=target[0]))
print(sol.twoSum(nums=nums[1], target=target[1]))
print(sol.twoSum(nums=nums[2], target=target[2]))

# 4. valid palindrome
s: List(str) = ["Was it a car or a cat I saw?", "tab a cat"]
print(sol.isPalindrome(s[0]))
print(sol.isPalindrome(s[1]))

# 5. best time to buy and sell stock
prices: List(List(int)) = [[10, 1, 5, 6, 7, 1], [10, 8, 7, 5, 2]]
print(sol.maxProfit(prices[0]))
print(sol.maxProfit(prices[1]))

# 6. valid parentheses
s: List(str) = ["[]", "([{}])", "[(])"]
print(sol.isValid(s[0]))
print(sol.isValid(s[1]))
print(sol.isValid(s[2]))

# 7. binary search
nums: List(int) = [-1, 0, 2, 4, 6, 8]
target: List(int) = [4, 3]
print(sol.search(nums, target=target[0]))
print(sol.search(nums, target=target[1]))

# 8. reverse linked list
head = build_linked_list([0, 1, 2, 3])
print(linked_list_to_list(sol.reverseList(head)))