import requests
import http.client
import os

from dotenv import load_dotenv


# get the solution of the link with the problem
def fetch_solution(link):
    conn = http.client.HTTPSConnection("raw.githubusercontent.com")
    headers = {
        'authority': "raw.githubusercontent.com",
        'accept': "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8",
        'accept-language': "en-US,en;q=0.9",
        'cache-control': "max-age=0",
        'if-none-match': 'W/"0a3ee7168e35b3e0c6c9f10e1bd361d390e71289d4653bb6d4acbb880d1f771b"',
        'sec-ch-ua': '"Brave";v="111", "Not(A:Brand";v="8", "Chromium";v="111"',
        'sec-ch-ua-mobile': "?0",
        'sec-ch-ua-platform': '"Linux"',
        'sec-fetch-dest': "document",
        'sec-fetch-mode': "navigate",
        'sec-fetch-site': "none",
        'sec-fetch-user': "?1",
        'sec-gpc': "1",
        'upgrade-insecure-requests': "1",
        'user-agent': "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36"
    }

    conn.request("GET", url=link, headers=headers)

    res = conn.getresponse()
    data = res.read()

    return data.decode("utf-8")


# the body of the text that added to the end of the file
def body_of_problem(problem):
    txt_to_add = f"""
<hr>
<br><br>

## {problem['number']})  [{problem['name']}](https://leetcode.com/problems/{problem['link']}/)

### Difficulty

![](https://img.shields.io/badge/{problem['difficulty']}-{problem['color']}?style=for-the-badge)

### Related Topic

{problem['tags']}

### Code


```cpp
{problem['solution']}
```
    """
    return txt_to_add


# parsing the date
def README_path(date):
    # split the date
    date = date.split("-")

    # get the month
    month = date[1]

    # months
    months = {
        "01": "Junyary",
        "02": "February",
        "03": "March",
        "04": "April",
        "05": "May",
        "06": "June",
        "07": "July",
        "08": "August",
        "09": "September",
        "10": "October",
        "11": "November",
        "12": "December",
    }

    # return the date
    return f'./{month}- {months[month]}/README.md'


# the title that add to the list
def title_of_problem(problem):
    txt_to_add = f"1. **[{problem['name']}](#{problem['number']}--{problem['link']})**\n"
    return txt_to_add


# read the file
def read_from_file(file_path):
    data = []
    # open the file
    with open(file_path, "r") as f:
        data = f.readlines()
    return data


# save the problem to the file to be used in the README.md
def save_to_file(problem):
    # get the README path
    file_path = README_path(date=problem['date'])
    file_data = read_from_file(file_path=file_path)
    save_title(file_path=file_path, txt=title_of_problem(problem), data=file_data)
    save_solution(file_path=file_path, txt=body_of_problem(problem))


# save the title
def save_title(file_path, txt, data):
    idx = data.index('## Problems:\n')
    for i in range(idx + 1, len(data)):
        if data[i] == '<hr>\n':
            data.insert(i - 1, txt)
            break

    # save to the file
    with open(file_path, "w") as f:
        f.writelines(data)


# def save the solution
def save_solution(file_path, txt):
    # append the solution in the end
    with open(file_path, "a") as f:
        f.write(txt)


def remove_author_line(solution):
    # split the solution
    solution = solution.split("\n")

    # remove the author line
    for line in solution:
        words = line.lower().split(" ")
        for word in words:
            if "author:" in word or (
                "author" in word and ":" in words and "author:" not in words
            ):
                solution.remove(line)
                break

    # join the solution
    solution = "\n".join(solution)

    # return the solution
    return solution


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

    # get the response as json and get the problem info
    response = response.json()
    response = response["data"]["activeDailyCodingChallengeQuestion"]

    # fetcht the solution
    try:
        link = os.getenv('LINK')
        if link is None:
            print('Missing Link in Environemnt Variable')
            exit(1)
        solution = fetch_solution(link=link)
    except Exception as e:
        print(e)
        exit(1)

    # remove the author line
    solution = remove_author_line(solution)

    # get the tags of the problem
    tags = ""
    for tag in response["question"]["topicTags"]:
        tags += f"`{tag['name']}` "

    # get the colors for the difficulty
    colors = {
        "easy": "green",
        "medium": "orange",
        "hard": "red"
    }

    # create the problem dictionary to return
    problem = {
        "date": response["date"],
        "name": response["question"]["title"],
        "number": response["date"].split('-')[-1],
        "difficulty": response["question"]["difficulty"],
        "link": response["question"]["titleSlug"],
        "color": colors[response["question"]["difficulty"].lower()],
        "solution": solution.strip(),
        "tags": tags.strip()
    }

    # return the problem name
    return problem


def main():
    load_dotenv()
    problem = get_daily_problem()
    save_to_file(problem)


if __name__ == '__main__':
    main()
