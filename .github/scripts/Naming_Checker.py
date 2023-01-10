import os
import re


def change_directory(dir=None, monthly=None, daily=None):
    if daily is not None and monthly is not None and dir is not None:
        os.chdir(f"{dir}/{monthly}/{daily}")
    elif monthly is not None and dir is not None:
        os.chdir(f"{dir}/{monthly}")
    elif dir is not None:
        os.chdir(f"{dir}")


def check_monthly_folders():
    # name of the folders should be in the directory
    folders_tempelate = [
        ".github",
        ".git",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ]

    # name of the folders in the directory
    folders = [f for f in os.listdir(".") if os.path.isdir(f)]

    # check if the folders are in the directory
    for folder in folders:
        if folder not in folders_tempelate:
            print(f"Folder {folder} name is not valid")
            exit(1)

    # if the folders is valid
    return folders


def check_daily_folders():

    # name of the folders should be in the directory
    folders_tempelate = ["README.md"]
    # name of the folders in the directory
    folders = [f for f in os.listdir() if os.path.isdir(f)]

    # check if the folders are in the directory
    for folder in folders:
        if (
            not re.match(
                r"[1-9]-|[1-2][0-9]-|[3[0-1]]-\s[A-Z[a-z]+\s|to\s|on\s|in\s|of\s]+", folder
            )
            and folder not in folders_tempelate
        ):
            print(f"Folder {folder} name is not valid")
            exit(1)

    # if the folders is valid
    return folders


def check_files():

    # name of the folders in the directory
    files = [f for f in os.listdir() if os.path.isfile(f)]

    # check if the folders are in the directory
    for file in files:
        if not re.match(
            r"[1-9]-|[1-2][0-9]-|[3[0-1]]-\s[A-Z[a-z]+\s|to\s|on\s|in\s|of\s]+([A-Za-z]+).[cpp|rb|py|js|ts|c|java|php|dart]",
            file,
        ):
            print(f"file {file} name is not valid")
            exit(1)


def main():
    # check folders in the repo
    monthly_folders = check_monthly_folders()

    # delete .github from them
    monthly_folders.remove(".github")
    monthly_folders.remove(".git")

    # directory of the root folder
    dir = os.getcwd()

    # check folders in the monthly folders
    for monthly_folder in monthly_folders:
        # change directory to the current monthly folder
        change_directory(monthly=monthly_folder, dir=dir)

        # check folders in the monthly folder
        daily_folders = check_daily_folders()

        for daily_folder in daily_folders:

            # change directory to the current daily folder
            change_directory(daily=daily_folder, monthly=monthly_folder, dir=dir)

            # check files in the daily folder
            check_files()

            # change directory to the monthly folder again
            change_directory(monthly=monthly_folder, dir=dir)

        # change directory to the main folder again
        change_directory(dir=dir)

    print("All files are valid")


if __name__ == "__main__":
    main()
