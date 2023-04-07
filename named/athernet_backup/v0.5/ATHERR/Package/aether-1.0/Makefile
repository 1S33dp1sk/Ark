

all:
	@mkdir -p usr/bin
	@cp scripts/* usr/bin
	@gcc ./parsers/CONF/config_reader.c parsers/CONF/main.c -o usr/bin/aether-reader
	@gcc ./parsers/JSON/json_parser.c parsers/JSON/main.c -o usr/bin/aether-jsonifier
	@chmod u+x usr/bin/*
	@mkdir -p etc/aether/configs
	@cp templates/configs/* etc/aether/configs
	@mkdir etc/aether/contracts
	@cp -r templates/contracts/* etc/aether/contracts
	@mkdir etc/aether/logs
	@cp templates/logs/rotation etc/aether/logs
	@mkdir -p var/log/aether
	@cp templates/logs/* var/log/aether


clean:
	@rm -rf usr
	@rm -rf var
	@rm -rf etc
	@rm -rf dev3.egg-info
