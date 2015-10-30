# Bradford Smith (bsmith8)
# Makefile for CS 577 Lab 6
# 10/28/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

AUTHOR=bsmith8
PROJECT=cs577-lab6
RM=rm -f
TEX=detailed_report.tex
PDFTEX=pdflatex

all:
	$(PDFTEX) $(TEX)

clean:
	$(RM) *.aux
	$(RM) *.log

fclean: clean
	$(RM) $(TEX:.tex=.pdf)

re: fclean all

tar: fclean
	tar -cvzf ../$(AUTHOR)_$(PROJECT).tar.gz ./*

