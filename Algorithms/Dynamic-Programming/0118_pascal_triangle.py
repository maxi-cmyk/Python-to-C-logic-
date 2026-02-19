#math

from typing import Optional

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
       #prev row[i-1] + prev_row[i]
       #C(n-1, k-1) + C(n-1, k) for coefficient (nested for loops)
        result = []
        if numRows == 0:
           return result

        first_row = [1]
        result.append(first_row)

        for i in range(1, numRows):
            prev_row = result[i-1]
            current_row = [1]

            for j in range(1, i):
                current_row.append(prev_row[j-1] + prev_row[j])
            
            #end the new row with 1
            current_row.append(1)
            result.append(current_row)

        return result

    



        