#include "storage_service.h"

#include <iostream>

#include "../bnet/Account.pb.h"
#include "../bnet/Hero.pb.h"
#include "../bnet/service/toon/toon.pb.h"
#include "../net/packet.h"

namespace d3emu
{
	namespace services
	{
		bool StorageDatabaseEngine::GetGameAccountSettings(Client &client, bnet::protocol::storage::ExecuteResponse &response)
		{
			// User should subclass this in order to customize

			// Default action is to do nothing
			return false;
		}

		StorageService::StorageService(uint32_t service_hash, uint8_t service_id)
			: Service(service_hash, service_id), has_database_engine_(false)
		{
		}

		StorageService::StorageService(uint32_t service_hash, uint8_t service_id, StorageDatabaseEngine *engine)
			: Service(service_hash, service_id) 
		{
		}

		net::PacketResponse *StorageService::ExecuteRequest(Client &client, net::PacketRequest &request_packet)
		{
			bnet::protocol::storage::ExecuteResponse *response =
				new bnet::protocol::storage::ExecuteResponse();

			bnet::protocol::storage::ExecuteRequest *execute_request =
				dynamic_cast<bnet::protocol::storage::ExecuteRequest *>(request_packet.message());
        
			if (!execute_request->query_name().compare("GetGameAccountSettings"))
			{
				for (int i = 0; i < execute_request->operations_size(); i++)
				{
					const bnet::protocol::storage::Operation &request_operation = execute_request->operations(i);
					bnet::protocol::storage::OperationResult *operation = response->add_results();

					operation->mutable_table_id()->set_hash(request_operation.table_id().hash());

					bnet::protocol::storage::Cell *cell = operation->add_data();

					cell->mutable_column_id()->set_hash(request_operation.column_id().hash());
					cell->mutable_row_id()->set_hash(request_operation.row_id().hash());
				}
			}
			else if (!execute_request->query_name().compare("LoadAccountDigest"))
			{
				D3::Account::Digest digest;
				digest.set_version(99);
				digest.set_flags(0);
				digest.mutable_last_played_hero_id()->set_id_high(0);
				digest.mutable_last_played_hero_id()->set_id_low(0);

				D3::Account::BannerConfiguration *banner_configuration = digest.mutable_banner_configuration();
				banner_configuration->set_background_color_index(0);
				banner_configuration->set_banner_index(0);
				banner_configuration->set_pattern(0);
				banner_configuration->set_pattern_color_index(0);
				banner_configuration->set_placement_index(0);
				banner_configuration->set_sigil_main(0);
				banner_configuration->set_sigil_accent(0);
				banner_configuration->set_sigil_color_index(0);
				banner_configuration->set_use_sigil_variant(false);

				for (int i = 0; i < execute_request->operations_size(); i++)
				{
					const bnet::protocol::storage::Operation &request_operation = execute_request->operations(i);
					bnet::protocol::storage::OperationResult *operation = response->add_results();

					operation->mutable_table_id()->set_hash(request_operation.table_id().hash());

					bnet::protocol::storage::Cell *cell = operation->add_data();

					cell->mutable_column_id()->set_hash(request_operation.column_id().hash());
					cell->mutable_row_id()->set_hash(request_operation.row_id().hash());
					cell->set_version(1);
					cell->set_data(digest.SerializeAsString());
				}
			}
			else if (!execute_request->query_name().compare("GetHeroDigests"))
			{
				D3::Hero::Digest digest;

				digest.set_version(99);
				digest.set_hero_name("auxxix");
				digest.set_gbid_class(0x4FB91EE2);
				digest.set_highest_unlocked_act(0);
				digest.set_highest_unlocked_difficulty(0);
				digest.set_last_played_act(0);
				digest.set_last_played_difficulty(0);
				digest.set_last_played_quest(0);
				digest.set_last_played_quest_step(0);
				digest.set_level(1);
				digest.set_player_flags(0);
				digest.set_time_played(0);
				digest.set_version(1);

				bnet::protocol::toon::ToonHandle handle;

				handle.set_id(0x96385C736E7D6EF5);
				handle.set_program(0x4433);
				handle.set_region(0x62);
				handle.set_realm(0x01);
		
				digest.mutable_hero_id()->set_id_low(handle.id());
				digest.mutable_hero_id()->set_id_high(0x300016200004433);

				// digest.mutable_hero_id()->ParseFromString(handle.SerializeAsString());

				/*
				D3::Hero::VisualItem *item =
					digest.mutable_visual_equipment()->add_visual_item();
				item->set_dye_type(0);
				item->set_effect_level(0);
				item->set_gbid(0);
				item->set_item_effect_type(0);
				*/
				for (int i = 0; i < execute_request->operations_size(); i++)
				{
					const bnet::protocol::storage::Operation &request_operation = execute_request->operations(i);
					bnet::protocol::storage::OperationResult *operation = response->add_results();

					operation->mutable_table_id()->set_hash(request_operation.table_id().hash());

					bnet::protocol::storage::Cell *cell = operation->add_data();

					cell->mutable_column_id()->set_hash(request_operation.column_id().hash());
					cell->mutable_row_id()->set_hash(request_operation.row_id().hash());
					cell->set_version(1);
					cell->set_data(digest.SerializeAsString());
				}
			}

			net::PacketResponse *response_packet = new net::PacketResponse();
			response_packet->set_message(response);
			response_packet->mutable_header()->set_service_id(0xfe);
			response_packet->mutable_header()->set_request_id(request_packet.header().request_id());
        
			return response_packet;
		}

		net::PacketResponse *StorageService::OpenTableRequest(Client &client, net::PacketRequest &request_packet)
		{
			bnet::protocol::storage::OpenTableResponse *response =
				new bnet::protocol::storage::OpenTableResponse();

			net::PacketResponse *response_packet = new net::PacketResponse();
			response_packet->set_message(response);
			response_packet->mutable_header()->set_service_id(0xfe);
			response_packet->mutable_header()->set_request_id(request_packet.header().request_id());
        
			return response_packet;
		}

		net::PacketResponse *StorageService::OpenColumnRequest(Client &client, net::PacketRequest &request_packet)
		{
			bnet::protocol::storage::OpenColumnResponse *response =
				new bnet::protocol::storage::OpenColumnResponse();
        
			net::PacketResponse *response_packet = new net::PacketResponse();
			response_packet->set_message(response);
			response_packet->mutable_header()->set_service_id(0xfe);
			response_packet->mutable_header()->set_request_id(request_packet.header().request_id());

			return response_packet;
		}

		net::PacketResponse *StorageService::Request(Client &client, net::PacketRequest &request_packet)
		{
			net::PacketResponse *response = 0;
			switch (request_packet.header().method_id())
			{
				case 0x01:
				{
					request_packet.set_message(new bnet::protocol::storage::ExecuteRequest());
					if (request_packet.message()->ParseFromString(request_packet.message_data()))
						response = this->ExecuteRequest(client, request_packet);
					else
						request_packet.clear_message();
					break;
				}

				case 0x02:
				{
					request_packet.set_message(new bnet::protocol::storage::OpenTableRequest());
					if (request_packet.message()->ParseFromString(request_packet.message_data()))
						response = this->OpenTableRequest(client, request_packet);
					else
						request_packet.clear_message();
					break;
				}

				case 0x03:
				{
					request_packet.set_message(new bnet::protocol::storage::OpenColumnRequest());
					if (request_packet.message()->ParseFromString(request_packet.message_data()))
						response = this->OpenColumnRequest(client, request_packet);
					else
						request_packet.clear_message();
					break;
				}
			}
        
			return response;
		}

		std::string StorageService::Name() const
		{
			return std::string("d3emu.net.StorageService");
		}

		void StorageService::set_database_engine(StorageDatabaseEngine *database_engine)
		{
			this->clear_has_database_engine();

			if (database_engine)
				this->set_has_database_engine();

			this->database_engine_ = database_engine;
		}

		StorageDatabaseEngine *StorageService::database_engine()
		{
			return this->database_engine_;
		}

		bool StorageService::has_database_engine()
		{
			return this->has_database_engine_;
		}

		void StorageService::set_has_database_engine()
		{
			this->has_database_engine_ = true;
		}

		void StorageService::clear_has_database_engine()
		{
			this->has_database_engine_ = false;

			if (this->database_engine_)
			{
				delete this->database_engine_;
				this->database_engine_ = 0;
			}
		}
	}
}