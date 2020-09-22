run_in_docker: clean
	umask 0000 && mkdir -p build
	docker run --rm \
		-v `pwd`:`pwd` \
		-w `pwd` \
	-it conanio/gcc5 sh -c 'umask 0000 && bash'

clean:
	rm -rf build
