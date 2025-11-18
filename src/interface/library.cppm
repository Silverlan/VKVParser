export module REDxEYE.VKVParser:library;

export import :kv_node;
export import :shared;

export namespace ValveKeyValueFormat {
	LIBRARY_API std::shared_ptr<KVNode> parseKVBuffer(const std::string& buffer);
	LIBRARY_API void setLogCallback(LoggerFunction loggerFunction);
};
