import requests
import os


# get the daily problem name
def get_daily_problem():
    # headers to send to the graphql
    headers = {
        'Content-Type': 'application/json',
    }

    # json data to send to the graphql
    json_data = {
        'query': 'query questionOfToday {\n\tactiveDailyCodingChallengeQuestion {\n\t\tdate\n\t\tuserStatus\n\t\tlink\n\t\tquestion {\n\t\t\tacRate\n\t\t\tdifficulty\n\t\t\tfreqBar\n\t\t\tfrontendQuestionId: questionFrontendId\n\t\t\tisFavor\n\t\t\tpaidOnly: isPaidOnly\n\t\t\tstatus\n\t\t\ttitle\n\t\t\ttitleSlug\n\t\t\thasVideoSolution\n\t\t\thasSolution\n\t\t\ttopicTags {\n\t\t\t\tname\n\t\t\t\tid\n\t\t\t\tslug\n\t\t\t}\n\t\t}\n\t}\n}\n',
        'operationName': 'questionOfToday',
    }

    # get the response from the graphql
    response = requests.post('https://leetcode.com/graphql', headers=headers, json=json_data)
    response = response.json()
    response = response['data']['activeDailyCodingChallengeQuestion']

    # return the problem name
    return response['question']['title'], response['date']


def parse_date(date):
    # split the date
    date = date.split('-')

    # get the month
    month = date[1]

    # get the day
    day = date[2]

    # return the date
    return month, day


def parse_month(month):

    months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

    return months[int(month) - 1]


def delete_solution(problem_name, day, month):

    # get the path to the file
    file = f'{month}/{day}- {problem_name}/{day}- {problem_name} (Ahmed Hossam).cpp'

    try:
        # open the file
        with open(file, 'r') as f:
            content = f.read().splitlines()

        if 'public:' not in content:
            try:
                # delete the file
                os.remove(str(file))
            except FileNotFoundError:
                print(f'{file} not found!')
    except FileNotFoundError:
        print(f'{file} not found!')


def main():
    # get the daily problem name
    problem_name, date = get_daily_problem()

    # parse the date
    month, day = parse_date(date)

    # parse the month
    month = parse_month(month)

    # delete the empty file
    delete_solution(problem_name, day, month)


if __name__ == "__main__":
    main()
