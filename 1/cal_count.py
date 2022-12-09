def count_calories(input: str) -> int:
    input = input.split("\n")
    net_cal_list = []
    
    temp = 0
    for line in input:
        if line != "":
            temp += int(line)
        else:
            net_cal_list += [temp]
            temp = 0
    return net_cal_list

def parse_result(cal_list: list, num_top_results=1) -> list:
    # Sort and make list descending
    cal_list.sort(reverse=True)

    return cal_list[0: num_top_results]

if __name__ == "__main__":
       with open("cal_count_input", "r") as file:
        
        # Get list with net calories each Elve carries
        net_cal_list = count_calories(file.read()) 

        # First solution
        print(parse_result(cal_list=net_cal_list))

        # Second solution
        print(sum(parse_result(cal_list=net_cal_list, num_top_results=3)))