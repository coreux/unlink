## Copyright 2012 Mo McRoberts.
##
##  Licensed under the Apache License, Version 2.0 (the "License");
##  you may not use this file except in compliance with the License.
##  You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
##  Unless required by applicable law or agreed to in writing, software
##  distributed under the License is distributed on an "AS IS" BASIS,
##  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
##  See the License for the specific language governing permissions and
##  limitations under the License.

DIST_SUBDIRS = en_GB

SUBDIRS = . $(NLS_SUBDIRS)

bin_PROGRAMS = unlink

doc_DATA = README LICENSE-2.0 unlink.1.html

unlink_SOURCES = unlink.c

dist_man1_MANS = unlink.1

unlink.1: unlink.1.xml
	$(XML2MAN) $<

unlink.1.html: unlink.1.xml
	$(XML2HTML) $< > $@
