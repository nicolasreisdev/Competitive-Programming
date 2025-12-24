import re

regex_pattern = r"[,.]"
print("\n".join(re.split(regex_pattern, input()))) # re.split() divide a string de acordo com o padrão regex
