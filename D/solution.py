def main():

    numbers_str = input().split()
    numbers = []
    for i in numbers_str:
        numbers.append(int(i))
    print(numbers[0] + numbers[1])

if __name__ == '__main__':
    main()
