k = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
N = 4

def printK(pool, prefix, n):
    # n is the length of the required result (number of char)
    if len(prefix) == n:
        # Halting Measure: when the prefix has the same amout of char as required n
        print(prefix)
        return
    else:
        for x in pool:
            newPrefix = prefix + x
            printK(pool, newPrefix, n)

printK(k, "", N)