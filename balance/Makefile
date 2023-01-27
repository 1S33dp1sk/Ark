aether:
	@cp packages/aether .
	@chmod u+x aether*
	@./aether init -f true
	@gcc packages/parsers/CONF/config_reader.c packages/parsers/CONF/reader.c -o Aether/bin/reader
	@gcc packages/parsers/JSON/json_parser.c packages/parsers/JSON/parser.c -o Aether/bin/parser

clean:
	@./aether purge
	@rm -rf aether*
	@rm -rf reader
	@rm -rf parser
