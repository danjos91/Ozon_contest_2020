def main():
    file = open('input.txt', 'r')
    targ = int(file.readline())
    numbers = list(map(int, file.read().split()))
    if targ % 2 == 0 and numbers.count(targ//2) > 1:
        open('output.txt', "w").write("1")
        return
    numbers_x = list(dict.fromkeys(numbers))
    for i in numbers_x:
        if i < targ:
            if (targ - i) in list(dict.fromkeys(numbers)) and i != (targ - i):
                open('output.txt', "w").write("1")
                return

    open('output.txt', "w").write("0")

if __name__ == '__main__':
    main()
