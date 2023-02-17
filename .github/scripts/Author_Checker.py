import os


# get folders in the current directory
def get_folders():
    return [f for f in os.listdir(".") if os.path.isdir(f)]


# get files in the current directory
def get_files():
    return [f for f in os.listdir(".") if os.path.isfile(f)]


# change directory to the given dir
def change_directory(dir=None, monthly=None, daily=None):
    if daily is not None and monthly is not None and dir is not None:
        os.chdir(f"{dir}/{monthly}/{daily}")
    elif monthly is not None and dir is not None:
        os.chdir(f"{dir}/{monthly}")
    elif dir is not None:
        os.chdir(f"{dir}")


# check the author line in the given file
def check_author_line(file=None):
    if file is not None:
        # ignore .gitkeep file
        if file == ".gitkeep":
            return

        with open(file, "r") as f:
            lines = f.readlines()
            for line in lines:
                words = line.lower().split(" ")
                for word in words:
                    if "author:" in word or (
                        "author" in word and ":" in words and "author:" not in words
                    ):
                        return

    print(f"Author line is not in {file} file")
    exit(1)


def main():
    # directory of the root folder
    dir = os.getcwd()

    # name of the folders should be in the directory
    monthly_folders = get_folders()

    # delete .git and .github folders
    monthly_folders.remove(".git")
    monthly_folders.remove(".github")

    for monthly_folder in monthly_folders:
        # change directory to the current monthly folder
        change_directory(monthly=monthly_folder, dir=dir)

        # get daily folders in the current monthly folder
        daily_folders = get_folders()

        for daily_folder in daily_folders:
            # change directory to the current daily folder
            change_directory(daily=daily_folder, monthly=monthly_folder, dir=dir)

            # get the files in the daily folder
            files = get_files()

            for file in files:
                # check the author line
                check_author_line(file=file)

            # change the directory to the monthly folder again
            change_directory(dir=dir, monthly=monthly_folder)

        # change directory to the root folder
        change_directory(dir=dir)


if __name__ == "__main__":
    main()
