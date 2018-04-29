library(dplyr)
library(ggplot2)
library(statsr)

data(arbuthnot)
# type in console
# view(arbuthnot)
# dim(arbuthnot)
# names(arbuthnot)
# arbuthnot$boys -> access the boys column

# ggplot(data = arbuthnot, aes(x=year, y=girls))+geom_point()


# ?ggplot
# to get a vector of sum of each year:
# arbuthnot$boys + arbuthnot$girls

# add a new column called total
# arbuthnot <- arbuthnot %>% 
#   mutate(total = boys + girls)

# ggplot(data = arbuthnot, aes(x = year, y = total)) +
#   geom_line() + geom_point()


# ggplot(data=arbuthnot, aes(x=year, y=boys/total)) + 
#   geom_line() + geom_point()

# arbuthnot <- arbuthnot %>%
#   mutate(more_boys=boys>girls)
#the data type is TRUE/FALSE

# to get the eange of years
# range(present$year)

# present <- present %>% 
#   mutate(total=boys+girls)
# 
# present <- present %>% 
#   mutate(prop_boys=boys/total)
# 
# ggplot(data=present, aes(x=year, y=prop_boys)) +
#   geom_point() +geom_line()
# 
# present <- present %>%
#   mutate(more_boys=boys>girls)
# 
# present$more_boys

# present <- present %>%
#   mutate(prop_boy_girl=boys/girls)
# 
# ggplot(data=present, aes(x=year, y=prop_boy_girl)) + 
#   geom_line() + geom_point()

# present %>%
#  # mutate(total = boys+girls) %>%
#  arrange(desc(total))