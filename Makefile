all:
	(cd timerLib; make install)
	(cd lcdLib; make install)
	(cd wakedemo; make)
#	(cd circledemo; make)
	(cd wakedemo_copy; make)
	(cd wakedemo_assembly)
	(cd wakedemo_square)
doc:
	rm -rf doxygen_docs
	doxygen Doxyfile
clean:
	(cd timerLib; make clean)
	(cd lcdLib; make clean)
#	(cd circledemo; make clean)
	(cd wakedemo; make clean)
	(cd wakedemo_copy; make clean)
	(cd wakedemo_assembly; make clean)
	(cd wakedemo_square; make clean)
	rm -rf lib h
	rm -rf doxygen_docs/*
