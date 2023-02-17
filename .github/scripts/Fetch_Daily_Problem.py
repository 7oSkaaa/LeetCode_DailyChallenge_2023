import json
import os

import requests


# get the daily problem name
def get_daily_problem():
    # headers to send to the graphql
    headers = {
        "Content-Type": "application/json",
    }

    # json data to send to the graphql
    json_data = {
        "query": "query questionOfToday {\n\tactiveDailyCodingChallengeQuestion {\n\t\tdate\n\t\tuserStatus\n\t\tlink\n\t\tquestion {\n\t\t\tacRate\n\t\t\tdifficulty\n\t\t\tfreqBar\n\t\t\tfrontendQuestionId: questionFrontendId\n\t\t\tisFavor\n\t\t\tpaidOnly: isPaidOnly\n\t\t\tstatus\n\t\t\ttitle\n\t\t\ttitleSlug\n\t\t\thasVideoSolution\n\t\t\thasSolution\n\t\t\ttopicTags {\n\t\t\t\tname\n\t\t\t\tid\n\t\t\t\tslug\n\t\t\t}\n\t\t}\n\t}\n}\n",
        "operationName": "questionOfToday",
    }

    # get the response from the graphql
    response = requests.post(
        "https://leetcode.com/graphql", headers=headers, json=json_data
    )
    response = response.json()
    response = response["data"]["activeDailyCodingChallengeQuestion"]

    # return the problem name
    return response["question"]["title"], response["date"]


def parse_date(date):
    # split the date
    date = date.split("-")

    # get the month
    month = date[1]

    # get the day
    day = date[2]

    # return the date
    return month, day


def parse_month(month):
    months = [
        "01- January",
        "02- February",
        "03- March",
        "04- April",
        "05- May",
        "06- June",
        "07- July",
        "08- August",
        "09- September",
        "10- October",
        "11- November",
        "12- December",
    ]

    return months[int(month) - 1]


def read_data():
    # read the data from the file
    with open(".github/data/problems.json", "r") as file:
        data = json.loads(file.read())

    # return the data
    return data


def write_data(data):
    # write the data to the file
    with open(".github/data/problems.json", "w") as file:
        json.dump(data, file, indent=4)


def append_folder(problem_name, day, month):
    print(f"{month}/{day}- {problem_name} folder created successfully!")

    # append to folder
    os.makedirs(f"{month}/{day}- {problem_name}", exist_ok=True)

    # change the path to the folder
    os.chdir(f"{month}/{day}- {problem_name}")

    # create .gitkeep file
    open(".gitkeep", "a").close()

    return f"{month}/{day}- {problem_name}"


def main():
    # get the daily problem name
    problem_name, date = get_daily_problem()

    # parse the date
    month, day = parse_date(date)

    # parse the month
    month = parse_month(month)

    # read the data from the file
    data = read_data()

    # check if the problem is already in the file
    if month not in data:
        data[month] = []

    monthly_problems = data[month]

    # add the problem to the file
    problem_to_add = {"day": day, "title": problem_name}

    if problem_to_add not in monthly_problems:
        monthly_problems.append(problem_to_add)

    # append the problem in data
    data[month] = monthly_problems

    # write the data to the file
    write_data(data)

    # append the folder to the directory
    return append_folder(problem_name, day, month)


if __name__ == "__main__":
    main()
