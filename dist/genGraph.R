library(ggplot2)
library(extrafont)
library(xkcd)

loadfonts()

data <- read.csv("data.csv", na.strings=c("nan", "inf"))
data <- data[data$us.Iteration != 0,]
plot <- ggplot(data, aes(Problem.Space, us.Iteration)) + xlab("Nombre de villes") + ylab("micro-secondes par iterations") + geom_line(aes(colour=Experiment)) + xkcdaxis(c(0,16),c(0,4150000)) + labs(colour="Heuristique")
ggsave("benchmarks.pdf", plot, height=5, width=8)
