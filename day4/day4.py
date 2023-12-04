

def getWinningAndActualNumbers(inputLine):
    twoparts = inputLine.strip().split(":")
    numbers = twoparts[1].split("|")
    winningNumbers = numbers[0].split(" ")
    winningNumbers = list(filter(None, winningNumbers))
    winningNumbers = [int(string) for string in winningNumbers] 

    actualNumbers = numbers[1].split(" ")
    actualNumbers = list(filter(None, actualNumbers))
    actualNumbers = [int(string) for string in actualNumbers] 

    return winningNumbers, actualNumbers

def count_lines(filename):
  """Counts the number of lines in a file.

  Args:
    filename: The name of the file to count the lines of.

  Returns:
    The number of lines in the file.
  """

  with open(filename, "r") as f:
    lines = f.readlines()

  return len(lines)

def part2():
    testFile = "./day4input.txt"
    numLines = count_lines(testFile)
    f = open(testFile, "r")
    totalSum = 0
    count = 0
    sumOfCards = [0] * numLines
    sumWinningNumbers = [None] * numLines
    for oneline in f:
        winningNumbers, actualNumbers = getWinningAndActualNumbers(oneline)

        actualNumbersInWinningList =  len([i for i in actualNumbers if i in winningNumbers ])

        sumOfCards[count] += 1

        if actualNumbersInWinningList > 0:
            for index in range(count+1, count + actualNumbersInWinningList + 1):
                sumOfCards[index] += sumOfCards[count]
            
        # Increment count
        count += 1
    
    for index in range(len(sumOfCards)):
        if sumOfCards[index] > 0:
            totalSum += sumOfCards[index]
        print("Index: ", index, ", Total Entries: ", sumOfCards[index])

    return totalSum

def part1():
    testFile = "./day4input.txt"
    f = open(testFile, "r")
    totalSum = 0
    for oneline in f:
        winningNumbers, actualNumbers = getWinningAndActualNumbers(oneline)

        actualNumbersInWinningList =  len([i for i in actualNumbers if i in winningNumbers ])
        sumWinningNumbers = 2**(actualNumbersInWinningList-1)
        if actualNumbersInWinningList > 0:
            print(actualNumbersInWinningList, ":", sumWinningNumbers)
            totalSum += sumWinningNumbers
    return totalSum

def main():
    # print(part1())
    print(part2())

if __name__ == "__main__":
    main()