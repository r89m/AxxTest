all: 
	$(MAKE) -C tests all
	
test:
	$(MAKE) -C tests test
	
clean:
	# Clean this folder
	@- rm *.o || true
	@- rm *.gcno || true
	@- rm *.gcda || true
	@- rm *.gcov || true
	
	# Clean include/ folder
	@- rm include/*.o || true
	@- rm include/*.gcno || true
	@- rm include/*.gcda || true
	@- rm include/*.gcov || true
	
	
	# Clean tests folder
	$(MAKE) -C tests clean